var data = [
  {
    product: 'โค้กส้ม (ขวด)',
    name: 'อติวงศ์ สุชาโต',
    price: 18.0,
  },
  {
    product: 'ข้าวผัดปู (เวฟด้วย)',
    name: 'ณัฐวุฒิ หนูไฟโรจน์',
    price: 45.0,
  },
  {
    product: 'ปูอัดแพ็คเล็ก',
    name: 'โปรดปราน บุญยพุกกณะ',
    price: 40.0,
  },
  {
    product: 'น้ำทิพย์ (เอาขวดไม่ยวบยาบ)',
    name: 'ณัฐวุฒิ หนูไฟโรจน์',
    price: 45.0,
  },
  {
    product: 'C-Vitt มะนาว',
    name: 'ณัฐวุฒิ หนูไฟโรจน์',
    price: 15.5,
  },
];

function renderSummary() {
  var summationData = {};
  var sumPrice = 0;

  for (var i = 0; i < data.length; i++) {
    if (data[i].name in summationData) {
      summationData[data[i].name] += parseInt(data[i].price);
    } else {
      summationData[data[i].name] = parseInt(data[i].price);
    }
    sumPrice += parseInt(data[i].price);
  }

  const summationContent = document.querySelector('#summation');
  var renderContent = `<p>จำนวนเงินรวม: ${sumPrice} บาท</p>`;

  for (const [key, value] of Object.entries(summationData)) {
    renderContent += `<p>${key} : ${value} บาท</p>`;
  }

  summationContent.innerHTML = renderContent;
}

function renderContent() {
  const tableContent = document.querySelector('#main-table-content');
  var renderContent = ``;
  for (var i = 0; i < data.length; i++) {
    renderContent += `<tr>
<td>${data[i].product}</td>
<td>${data[i].name}</td>
<td>${data[i].price}</td>
<td><button class="delete-row" onclick="removeRow(${i})">ลบ</button></td>
</tr>
`;
  }
  renderContent += `<tr>
    <td><input id="name-to-add" /></td>
    <td>
      <select name="name" id="item-to-add">
        <option value="" disabled selected>-- เลือกผู้ฝากซื้อ --</option>
        <option value="ภณ วาณิชยชลกิจ">ภณ วาณิชยชลกิจ</option>
        <option value="ธนัส วงศ์สมุทร">ธนัส วงศ์สมุทร</option>
        <option value="นวนนท์ เนกขัมม์">นวนนท์ เนกขัมม์</option>
        <option value="สิรพัชร์ ธรรมลีลากุล">สิรพัชร์ ธรรมลีลากุล</option>
        <option value="อติวงศ์ สุชาโต">อติวงศ์ สุชาโต</option>
        <option value="โปรดปราน บุญยพุกกณะ">โปรดปราน บุญยพุกกณะ</option>
        <option value="ณัฐวุฒิ หนูไฟโรจน์">ณัฐวุฒิ หนูไฟโรจน์</option>
      </select>
    </td>
    <td><input id="price-to-add" type="number" /></td>
    <td><button id="add-newrow" onclick="addRow()"> เพิ่ม</button></td>
  </tr>`;
  tableContent.innerHTML = renderContent;

  renderSummary();
}

function removeRow(index) {
  if (index > -1) {
    data.splice(index, 1);
  }
  renderContent();
}

function addRow() {
  const addProduct = document.getElementById('name-to-add').value;
  const addName = document.getElementById('item-to-add').value;
  const addPrice = document.getElementById('price-to-add').value;

  data.push({
    product: addProduct,
    name: addName,
    price: addPrice,
  });

  renderContent();
}

renderContent();
