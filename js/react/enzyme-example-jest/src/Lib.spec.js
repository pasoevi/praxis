import { orderTotal, someOrder } from './Lib';


it('calculates order total correctly', () => {
    expect(orderTotal(someOrder)).toBe(80);
});