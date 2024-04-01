const frontendIPAddress = '44.215.199.124';
const backendIPAddress = '44.215.199.124:3000';

let allCourses = [];

const authorizeApplication = () => {
  window.location.href = `http://${backendIPAddress}/courseville/auth_app`;
};

// Get user profile
const getUserProfile = async () => {
  const options = {
    method: 'GET',
    credentials: 'include',
  };
  await fetch(`http://${backendIPAddress}/courseville/get_profile_info`, options)
    .then((response) => {
      if (response.status == 401) {
        window.location.href = `http://${frontendIPAddress}/login.html`;
      }
      return response.json();
    })
    .then((data) => {
      console.log(data.user);
      document.getElementById('profile_name').innerHTML =
        data.user.firstname_th + ' ' + data.user.lastname_th;
    })
    .catch((error) => console.error(error));
};

// Get all courses
const getAllCourses = async () => {
  const options = {
    method: 'GET',
    credentials: 'include',
  };
  await fetch(`http://${backendIPAddress}/courseville/get_courses`, options)
    .then((response) => response.json())
    .then((courses) => {
      allCourses = courses;
    })
    .catch((error) => {
      console.error(error);
      allCourses = [];
    });

  await renderCreateCoursesChoices();
};

// Get all courses and make it create options
const renderCreateCoursesChoices = async () => {
  const selectSubjectElement = document.getElementById('create_subject');
  selectSubjectElement.innerHTML = `<option value="" disabled selected>เลือกวิชา</option>`;
  allCourses.map((course) => {
    selectSubjectElement.innerHTML += `<option value="${course.cv_cid}">${course.title}</option>`;
  });
};

// Get all courses and make it edit options
const renderEditCoursesChoices = async () => {
  const selectSubjectElement = document.getElementById('edit_subject');
  selectSubjectElement.innerHTML = `<option value="" disabled selected>เลือกวิชา</option>`;
  allCourses.map((course) => {
    selectSubjectElement.innerHTML += `<option value="${course.cv_cid}">${course.title}</option>`;
  });
};

// Logout
const logout = async () => {
  window.location.href = `http://${backendIPAddress}/courseville/logout`;
};
