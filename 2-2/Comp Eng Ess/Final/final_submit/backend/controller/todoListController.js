const dotenv = require('dotenv');
dotenv.config();
const https = require('https');

const { v4: uuidv4 } = require('uuid');
const { DynamoDBClient } = require('@aws-sdk/client-dynamodb');
const { ScanCommand, PutCommand, UpdateCommand, DeleteCommand } = require('@aws-sdk/lib-dynamodb');
const { error } = require('console');

const docClient = new DynamoDBClient({ regions: process.env.AWS_REGION });

// Get request UID
const getUID = async (req) => {
  let UID = '';

  try {
    const uidPromise = new Promise((resolve, reject) => {
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
            resolve(JSON.parse(profileData).user.id);
          });
        }
      );
      profileReq.on('error', (err) => {
        reject(err);
        console.error(err);
      });
      profileReq.end();
    });

    UID = await uidPromise;
  } catch (error) {
    console.log(error);
    console.log('Please logout, then login again.');
  }
  return UID;
};

// Get todo lists from DynamoDB
exports.getTodoLists = async (req, res) => {
  const UID = await getUID(req);

  const params = {
    TableName: process.env.aws_todo_lists_table_name,
    FilterExpression: '#uid = :v_uid',
    ExpressionAttributeNames: {
      '#uid': 'uid',
    },
    ExpressionAttributeValues: {
      ':v_uid': UID,
    },
  };
  try {
    const data = await docClient.send(new ScanCommand(params));
    console.log('getting todo lists from the database');
    res.send(data.Items);
  } catch (err) {
    console.error(err);
    res.status(500).send(err);
  }
};

// Add todo lists to DynamoDB
exports.addTodoLists = async (req, res) => {
  const UID = await getUID(req);
  const todo_list_id = uuidv4();
  const item = { todo_list_id: todo_list_id, ...req.body, uid: UID };

  const params = {
    TableName: process.env.aws_todo_lists_table_name,
    Item: item,
  };

  try {
    const response = await docClient.send(new PutCommand(params));
    console.log('adding todo lists to the database');
    res.send(response);
  } catch (err) {
    console.error(err);
    res.status(500).send(err);
  }
};

// Update todo lists to DynamoDB
exports.updateTodoList = async (req, res) => {
  const todo_list_id = req.params.todo_list_id;

  const title = req.body.title;
  const subject = req.body.subject;
  const priority = req.body.priority;
  const date = req.body.date;
  const time = req.body.time;
  const status = req.body.status;

  const params = {
    TableName: process.env.aws_todo_lists_table_name,
    Key: {
      todo_list_id: todo_list_id,
    },
    UpdateExpression:
      'set #title = :v_title, #subject = :v_subject, #priority = :v_priority, #date = :v_date, #time = :v_time, #status = :v_status',
    ExpressionAttributeNames: {
      '#title': 'title',
      '#subject': 'subject',
      '#priority': 'priority',
      '#date': 'date',
      '#time': 'time',
      '#status': 'status',
    },
    ExpressionAttributeValues: {
      ':v_title': title,
      ':v_subject': subject,
      ':v_priority': priority,
      ':v_date': date,
      ':v_time': time,
      ':v_status': status,
    },
    ReturnValues: 'ALL_NEW',
  };

  try {
    const response = await docClient.send(new UpdateCommand(params));
    console.log(`update todo list id = ${todo_list_id} in the database`);
    res.send(response);
  } catch (err) {
    console.error(err);
    res.status(500).send(err);
  }
};

// Delete an item from DynamDB
exports.deleteTodoList = async (req, res) => {
  const todo_list_id = req.params.todo_list_id;

  const params = {
    TableName: process.env.aws_todo_lists_table_name,
    Key: { todo_list_id: todo_list_id },
  };

  try {
    const response = await docClient.send(new DeleteCommand(params));
    console.log(`deleting todo list id = ${todo_list_id} from the database`);
    res.send(response);
  } catch (err) {
    console.error(err);
    res.status(500).send(err);
  }
};
