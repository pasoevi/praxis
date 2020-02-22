import { findPeak } from "./peak";

test('finds peak', () => {
    const array = [5, 10, 20, 15];
    expect(findPeak(array)).toBe(20);
})