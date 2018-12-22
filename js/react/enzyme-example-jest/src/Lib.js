const someOrder = {
    items: [
        {
            item: 'MP3 player',
            price: 12.1,
            quantity: 1
        },
        {
            item: 'Winter coat',
            price: 45,
            quantity: 1
        },
        {
            item: 'USB Type-C cable',
            price: 7.9,
            quantity: 1
        },
        {
            name: 'Shipping',
            price: 15,
            shipping: true
        }
    ]
};

const orderTotal = order => {
    const totalItems = order.items.filter(item => !item.shipping).reduce((sum, item) => (item.price * item.quantity) + sum, 0);
    const shippingItem = order.items.find(x => !!x.shipping);
    const shippingCost = totalItems >= 1000 ? 0 : shippingItem.price;

    return shippingCost + totalItems;
}

const result = orderTotal(someOrder)

export {
    someOrder,
    orderTotal
};