function validFragment(fragment) {
    const digits = [1, 2, 3, 4, 5, 6, 7, 8, 9];

    return fragment.length === 9 && digits.every(el => fragment.includes(el));
}

function decompose(board) {
    
}
