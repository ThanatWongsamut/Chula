const express = require('express');
const itemsController = require('../controller/todoListController');

const router = express.Router();

router.get('/', itemsController.getTodoLists);
router.post('/', itemsController.addTodoLists);
router.patch('/:todo_list_id', itemsController.updateTodoList);
router.delete('/:todo_list_id', itemsController.deleteTodoList);

module.exports = router;
