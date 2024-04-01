// const backendIPAddress = '127.0.0.1:3000';

let todoListsData;
let editingListID = '';

let filterOptions = {
  title: '',
  priority: 'all',
  status: 'all',
  sort: 'ascending',
};

const getTodoList = async () => {
  var myHeaders = new Headers();

  var requestOptions = {
    method: 'GET',
    headers: myHeaders,
    redirect: 'follow',
    credentials: 'include',
  };

  todoListsData = await fetch(`http://${backendIPAddress}/todoLists`, requestOptions)
    .then((response) => response.text())
    .then((result) => {
      // console.log(JSON.parse(result));
      return JSON.parse(result);
    })
    .catch((error) => {
      console.log('error', error);
      return [];
    });
};

const addTodoList = async () => {
  const title = document.getElementById('create_title').value;
  const subject = document.getElementById('create_subject').value;
  const priority = document.getElementById('create_priority').value;
  const date = document.getElementById('create_date').value;
  const time = document.getElementById('create_time').value;

  var myHeaders = new Headers();
  myHeaders.append('Content-Type', 'application/json');

  var raw = JSON.stringify({
    title: title,
    subject: subject,
    priority: priority,
    date: date,
    time: time,
    status: 'ongoing',
  });

  var requestOptions = {
    method: 'POST',
    headers: myHeaders,
    body: raw,
    redirect: 'follow',
    credentials: 'include',
  };

  fetch(`http://${backendIPAddress}/todoLists`, requestOptions)
    .then(async () => await redrawDOM())
    .catch((error) => console.log('error', error));
};

const enableEdit = (todo_list_id) => {
  editingListID = todo_list_id;
  redrawDOM();
};

const updateTodoList = async (todo_list_id) => {
  const title = document.getElementById('edit_title').value;
  const subject = document.getElementById('edit_subject').value;
  const priority = document.getElementById('edit_priority').value;
  const date = document.getElementById('edit_date').value;
  const time = document.getElementById('edit_time').value;

  var myHeaders = new Headers();
  myHeaders.append('Content-Type', 'application/json');

  var raw = JSON.stringify({
    title: title,
    subject: subject,
    priority: priority,
    date: date,
    time: time,
    status: 'ongoing',
  });

  var requestOptions = {
    method: 'PATCH',
    headers: myHeaders,
    body: raw,
    redirect: 'follow',
    credentials: 'include',
  };

  await fetch(`http://${backendIPAddress}/todoLists/${todo_list_id}`, requestOptions)
    .then(async () => {
      enableEdit('');
      await redrawDOM();
    })
    .catch((error) => console.log('error', error));
};

const markAsDoneTodoList = async (todo_list_id) => {
  var myHeaders = new Headers();
  myHeaders.append('Content-Type', 'application/json');

  const focusTodoList = todoListsData.filter(
    (todoListData) => todoListData.todo_list_id == todo_list_id
  )[0];
  var raw = JSON.stringify({
    title: focusTodoList.title,
    subject: focusTodoList.subject,
    priority: focusTodoList.priority,
    date: focusTodoList.date,
    time: focusTodoList.time,
    status: 'done',
  });

  var requestOptions = {
    method: 'PATCH',
    headers: myHeaders,
    body: raw,
    redirect: 'follow',
    credentials: 'include',
  };

  await fetch(`http://${backendIPAddress}/todoLists/${todo_list_id}`, requestOptions)
    .then(async () => await redrawDOM())
    .catch((error) => console.log('error', error));
};

const markAsOngoingTodoList = async (todo_list_id) => {
  var myHeaders = new Headers();
  myHeaders.append('Content-Type', 'application/json');

  const focusTodoList = todoListsData.filter(
    (todoListData) => todoListData.todo_list_id == todo_list_id
  )[0];
  var raw = JSON.stringify({
    title: focusTodoList.title,
    subject: focusTodoList.subject,
    priority: focusTodoList.priority,
    date: focusTodoList.date,
    time: focusTodoList.time,
    status: 'ongoing',
  });

  var requestOptions = {
    method: 'PATCH',
    headers: myHeaders,
    body: raw,
    redirect: 'follow',
    credentials: 'include',
  };

  await fetch(`http://${backendIPAddress}/todoLists/${todo_list_id}`, requestOptions)
    .then(async () => await redrawDOM())
    .catch((error) => console.log('error', error));
};

const deleteTodoList = async (todo_list_id) => {
  var myHeaders = new Headers();

  var requestOptions = {
    method: 'DELETE',
    headers: myHeaders,
    redirect: 'follow',
    credentials: 'include',
  };

  await fetch(`http://${backendIPAddress}/todoLists/${todo_list_id}`, requestOptions)
    .then(async () => await redrawDOM())
    .catch((error) => console.log('error', error));
};

const renderTodoLists = async () => {
  const ongoingTodoListsElement = document.getElementById('ongoing_todo_lists');
  const doneTodoListsElement = document.getElementById('done_todo_lists');

  const chipColor = (priority) => {
    switch (priority) {
      case 'most_important':
        return 'bg-red-900';
      case 'important':
        return 'bg-red-600';
      case 'normal':
        return 'bg-blue-600';
      case 'not_important':
        return 'bg-gray-600';
    }
  };

  const priorityText = (priority) => {
    switch (priority) {
      case 'most_important':
        return 'สำคัญมาก';
      case 'important':
        return 'สำคัญ';
      case 'normal':
        return 'ทั่วไป';
      case 'not_important':
        return 'ไม่สำคัญ';
    }
  };

  ongoingTodoListsElement.innerHTML = '';
  doneTodoListsElement.innerHTML = '';

  filteredTodoListsData = todoListsData.filter((todoListData) => {
    let matchTitle;
    let matchPriority;
    let matchStatus;

    matchTitle = todoListData.title.match(new RegExp(filterOptions.title, 'i'));

    if (filterOptions.priority == 'all') {
      matchPriority = true;
    } else {
      matchPriority = todoListData.priority == filterOptions.priority;
    }

    if (filterOptions.status == 'all') {
      matchStatus = true;
    } else {
      matchStatus = todoListData.status == filterOptions.status;
    }

    return matchTitle && matchPriority && matchStatus;
  });

  filteredTodoListsData.sort((a, b) => {
    if (filterOptions.sort == 'ascending') {
      return new Date(a.date + ' ' + a.time) > new Date(b.date + ' ' + b.time) ? 1 : -1;
    }

    if (filterOptions.sort == 'descending') {
      return new Date(a.date + ' ' + a.time) > new Date(b.date + ' ' + b.time) ? -1 : 1;
    }
  });

  if (allCourses.length == 0) {
    await getAllCourses();
  }

  filteredTodoListsData
    .filter((todoListData) => todoListData.status == 'ongoing')
    .map(async (todoListData) => {
      if (todoListData.todo_list_id != editingListID) {
        const todoListDate = new Date(todoListData.date);

        const todoListCourse = allCourses.filter(
          (course) => course.cv_cid == todoListData.subject
        )[0].title;

        ongoingTodoListsElement.innerHTML += `
          <div class="grid grid-cols-12 gap-4 w-full shadow-lg rounded-lg px-8 py-4 items-center mt-4">
            <div class="col-span-12">
              <div class="flex items-center">
                <p class="text-xl font-bold mr-4">${todoListData.title}</p>
                <div class="text-xs text-white rounded-full px-4 py-1 ${chipColor(
                  todoListData.priority
                )}">${priorityText(todoListData.priority)}</div>
              </div>

              <div>
                  <span class="text-lg">${todoListCourse}</span>
              </div>
      
              <span class="text-sm">${todoListDate.getDate()}/${
          todoListDate.getMonth() + 1
        }/${todoListDate.getFullYear()} ${todoListData.time}</span>
            </div>
      
            <div class="col-span-12 flex justify-end gap-4">
              <button class="bg-red-600 text-white px-6 py-2 rounded-lg" onclick="deleteTodoList('${
                todoListData.todo_list_id
              }')">ลบ</button>
              <button class="bg-yellow-600 text-amber-950 px-6 py-2 rounded-lg" onclick="enableEdit('${
                todoListData.todo_list_id
              }')">แก้ไข</button>
              <button class="bg-green-600 text-white px-6 py-2 rounded-lg" onclick="markAsDoneTodoList('${
                todoListData.todo_list_id
              }')">เสร็จสิ้น</button>
            </div>
          </div>
      `;
      } else {
        ongoingTodoListsElement.innerHTML += `
          <div class="shadow-lg rounded-lg px-8 py-8">
            <form action="javascript:updateTodoList('${todoListData.todo_list_id}')">
              <div class="">
                <textarea id="edit_title" name="edit_title" class="w-full bg-gray-100 text-lg px-2 py-2 rounded-lg"
                  placeholder="ใส่ชื่องาน/สิ่งที่ต้องทำตรงนี้"></textarea>
              </div>

              <div class="pt-4 grid grid-cols-12 gap-4">
                <div class="col-span-12 md:col-span-5 flex justify-between md:justify-start items-center gap-4">
                  <select name="edit_subject" id="edit_subject" defaultValue=""
                    class="py-2 px-2 border-solid border-b-2 border-gray-400 max-w-3xs">
                    <option value="" disabled selected>
                      เลือกวิชา
                    </option>
                  </select>

                  <select name="edit_priority" id="edit_priority" defaultValue=""
                    class="py-2 px-2 border-solid border-b-2 border-gray-400 max-w-3xs md:max-w-2xs">
                    <option value="" disabled selected>
                      ลำดับความสำคัญ
                    </option>
                    <option value="most_important">สำคัญมาก</option>
                    <option value="important">สำคัญ</option>
                    <option value="normal">ทั่วไป</option>
                    <option value="not_important">ไม่สำคัญ</option>
                  </select>
                </div>

                <div class="col-span-12 md:col-span-5 flex justify-between md:justify-start items-center gap-4">
                  <input type="date" id="edit_date" name="edit_date"
                    class="py-2 px-2 border-solid border-b-2 border-gray-400"></input>

                  <input type="time" id="edit_time" name="edit_time"
                    class="py-2 px-2 border-solid border-b-2 border-gray-400"></input>
                </div>

                <div class="col-span-12 md:col-span-2 flex justify-end">
                  <button class="px-6 py-2 rounded-lg" onclick="enableEdit('')">ยกเลิก</button>
                  <button class="bg-blue-600 text-white px-6 py-2 rounded-lg" type="submit">ยืนยัน</button>
                </div>
              </div>
            </form>
          </div>
        `;

        await renderEditCoursesChoices();
        document.getElementById('edit_title').value = todoListData.title;
        document.getElementById('edit_subject').value = todoListData.subject;
        document.getElementById('edit_priority').value = todoListData.priority;
        document.getElementById('edit_date').value = todoListData.date;
        document.getElementById('edit_time').value = todoListData.time;
      }
    });

  filteredTodoListsData
    .filter((todoListData) => todoListData.status == 'done')
    .map((todoListData) => {
      const todoListDate = new Date(todoListData.date);
      const todoListCourse = allCourses.filter((course) => course.cv_cid == todoListData.subject)[0]
        .title;
      doneTodoListsElement.innerHTML += `
          <div class="grid grid-cols-12 gap-4 w-full shadow-lg rounded-lg px-8 py-4 items-center bg-gray-200 mt-4">
            <div class="col-span-12">
              <div class="flex items-center">
                <p class="line-through text-xl text-gray-500 font-bold mr-4">
                  ${todoListData.title}
                </p>
                <div class="text-xs text-white rounded-full px-4 py-1 bg-gray-300">${priorityText(
                  todoListData.priority
                )}</div>
              </div>

              <div>
                <span class="text-lg text-gray-500">${todoListCourse}</span>
              </div>

              <span class="text-sm text-gray-400">${todoListDate.getDate()}/${
        todoListDate.getMonth() + 1
      }/${todoListDate.getFullYear()} ${todoListData.time}</span>
            </div>

            <div class="col-span-12 flex justify-end gap-4">
              <button class="bg-red-600 text-white px-6 py-2 rounded-lg" onclick="deleteTodoList('${
                todoListData.todo_list_id
              }')">ลบ</button>
              <button class="bg-indigo-900 text-white px-6 py-2 rounded-lg" onclick="markAsOngoingTodoList('${
                todoListData.todo_list_id
              }')">ยังไม่เสร็จ</button>
            </div>
          </div>
    `;
    });
};

const redrawDOM = async () => {
  // window.document.dispatchEvent(
  //   new Event('DOMContentLoaded', {
  //     bubbles: true,
  //     cancelable: true,
  //   })
  // );

  // console.log(allCourses);

  if (allCourses.length == 0) {
    // console.log('Loading all courses');
    await getAllCourses();
  }

  await getTodoList();
  await renderTodoLists();

  document.getElementById('create_title').value = '';
  document.getElementById('create_subject').value = '';
  document.getElementById('create_priority').value = '';
  document.getElementById('create_date').value = null;
  document.getElementById('create_time').value = null;
};

const searchTitleChangeHandler = (event) => {
  // console.log(event.value);
  filterOptions.title = event.value;
};

const searchPriorityChangeHandler = (event) => {
  // console.log(event.value);
  filterOptions.priority = event.value;
};

const searchStatusChangeHandler = (event) => {
  // console.log(event.value);
  filterOptions.status = event.value;
};

const sortChangeHandler = async (event) => {
  // console.log(event.value);
  filterOptions.sort = event.value;
  await redrawDOM();
};

// document.addEventListener('DOMContentLoaded', async function (event) {
//   console.log('Getting data from server');
//   if (allCourses == []) {
//     await getAllCourses();
//   }

//   // Waiting until all courses is loaded
//   while (allCourses == []) {}

//   await getTodoList();
//   renderTodoLists();
// });

redrawDOM();
