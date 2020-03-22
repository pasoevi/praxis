fs = require("fs")

// A function to create an order object.
// Not a constuctor function, no need to use new when creating an instance.
function order(orderId, companyName, customerAddress, orderedItem) {
  return Object.freeze({
    orderId: orderId,
    companyName: companyName,
    customerAddress: customerAddress,
    orderedItem: orderedItem
  });
}

function ordersFromCompany(company) {
  return orders.filter(o => o.companyName === company);
}

function ordersToAddress(address) {
  return orders.filter(o => o.customerAddress === address);
}

// Returns a new array without the deleted element.
// Doesn't update the orders array
function deleteOrderExample(orderId) {
  return orders.filter(o => o.orderId !== orderId);
}

function deleteOrder(orderId) {
  const idx = orders.findIndex(o => o.orderId === orderId);
  if (idx > -1) {
    orders.splice(idx, 1);
  }
}

function itemStats(orders) {
  const stats = [];

  orders.forEach(function(o) {
    const item = stats.find(s => s.item === o.orderedItem);
    if (item) {
      item.frequency += 1;
    } else {
      stats.push({
        frequency: 1,
        item: o.orderedItem
      });
    }
  });

  // Return stats sorted by how often each item was sold in descending order.
  return stats.sort((a, b) => b.frequency - a.frequency);
}

const orders = [];

fs.readFile("sample.txt", "utf8", function(err, data) {
  const ordersText = data.split("\r\n");
  ordersText.forEach(line => orders.push(order(...line.split(", "))));

  const company = "SuperTrader";
  const address = "Reeperbahn 153";

  console.log("Stats");
  console.log(itemStats(orders));

  deleteOrder("001");
  console.log(`Orders to ${address}:`);
  console.log(ordersToAddress(address));
  console.log("All orders: ");
  console.log(orders);
});
