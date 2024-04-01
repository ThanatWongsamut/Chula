const dotenv = require('dotenv');
dotenv.config();
const https = require('https');
const url = require('url');
const querystring = require('querystring');

const redirect_uri = `http://${process.env.backendIPAddress}/courseville/access_token`;
const authorization_url = `https://www.mycourseville.com/api/oauth/authorize?response_type=code&client_id=${process.env.client_id}&redirect_uri=${redirect_uri}`;
const access_token_url = 'https://www.mycourseville.com/api/oauth/access_token';

// Get auth app
exports.authApp = (req, res) => {
  res.redirect(authorization_url);
};

// Parsing the Authorization access token
exports.accessToken = (req, res) => {
  const parsedUrl = url.parse(req.url);
  const parsedQuery = querystring.parse(parsedUrl.query);

  if (parsedQuery.error) {
    res.writeHead(400, { 'Content-Type': 'text/plain' });
    res.end(`Authorization error: ${parsedQuery.error_description}`);
    return;
  }

  if (parsedQuery.code) {
    const postData = querystring.stringify({
      grant_type: 'authorization_code',
      code: parsedQuery.code,
      client_id: process.env.client_id,
      client_secret: process.env.client_secret,
      redirect_uri: redirect_uri,
    });

    const tokenOptions = {
      method: 'POST',
      headers: {
        'Content-Type': 'application/x-www-form-urlencoded',
        'Content-Length': postData.length,
      },
    };

    const tokenReq = https.request(access_token_url, tokenOptions, (tokenRes) => {
      let tokenData = '';
      tokenRes.on('data', (chunk) => {
        tokenData += chunk;
      });
      tokenRes.on('end', () => {
        const token = JSON.parse(tokenData);
        req.session.token = token;
        console.log(req.session);
        if (token) {
          res.writeHead(302, {
            Location: `http://${process.env.frontendIPAddress}/`,
          });
          res.end();
        }
      });
    });
    tokenReq.on('error', (err) => {
      console.error(err);
    });
    tokenReq.write(postData);
    tokenReq.end();
  } else {
    res.writeHead(302, { Location: authorization_url });
    res.end();
  }
};

// Send "GET" request to CV endpoint to get user profile information
exports.getProfileInformation = (req, res) => {
  try {
    const profileOptions = {
      headers: {
        Authorization: `Bearer ${req.session.token.access_token}`,
      },
    };
    const profileReq = https.request(
      'https://www.mycourseville.com/api/v1/public/users/me',
      profileOptions,
      (profileRes) => {
        let profileData = '';
        profileRes.on('data', (chunk) => {
          profileData += chunk;
        });
        profileRes.on('end', () => {
          const profile = JSON.parse(profileData);
          res.send(profile);
          res.end();
        });
      }
    );
    profileReq.on('error', (err) => {
      console.error(err);
    });
    profileReq.end();
  } catch (error) {
    console.log(error);
    console.log('Please logout, then login again.');
    res.status(401);
    res.end();
  }
};

// Send "GET" request to CV endpoint to get all courses that you enrolled
exports.getCourses = async (req, res) => {
  try {
    const courseInfosPromise = new Promise((resolve, reject) => {
      const courseOptions = {
        headers: {
          Authorization: `Bearer ${req.session.token.access_token}`,
        },
      };

      const courseReq = https.request(
        'https://www.mycourseville.com/api/v1/public/get/user/courses',
        courseOptions,
        (courseRes) => {
          let courseData = '';
          courseRes.on('data', (chunk) => {
            courseData += chunk;
          });
          courseRes.on('end', () => {
            resolve(JSON.parse(courseData).data.student);
          });
        }
      );
      courseReq.on('error', (err) => {
        console.error(err);
      });
      courseReq.end();
    });

    const courseInfos = await courseInfosPromise;

    const courseNamesPromise = courseInfos.map(async (courseInfo) => {
      const courseNamePromise = new Promise((resolve, reject) => {
        const courseOptions = {
          headers: {
            Authorization: `Bearer ${req.session.token.access_token}`,
          },
        };

        const courseReq = https.request(
          `https://www.mycourseville.com/api/v1/public/get/course/info?cv_cid=${courseInfo.cv_cid}`,
          courseOptions,
          (courseRes) => {
            let courseData = '';
            courseRes.on('data', (chunk) => {
              courseData += chunk;
            });
            courseRes.on('end', () => {
              resolve({
                cv_cid: JSON.parse(courseData).data.cv_cid,
                title: `${JSON.parse(courseData).data.title} (${
                  JSON.parse(courseData).data.course_no
                })`,
              });
            });
          }
        );
        courseReq.on('error', (err) => {
          console.error(err);
        });
        courseReq.end();
      });

      const courseName = await courseNamePromise;
      return courseName;
    });

    const courseNames = await Promise.all(courseNamesPromise);
    res.send(courseNames);
    res.end();
  } catch (error) {
    console.log(error);
    console.log('Please logout, then login again.');
    res.status(401);
    res.end();
  }
};

// Logout route
exports.logout = (req, res) => {
  req.session.destroy();
  res.redirect(`http://${process.env.frontendIPAddress}/login.html`);
  res.end();
};
