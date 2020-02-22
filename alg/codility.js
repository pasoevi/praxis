
class BrandCollector {
    index = 0;
    get brands() {
        return [
            'Docler',
            'LiveJasmin',
            'Oranum',
            'Google',
            'Apple',
            'Coca-Cola'
        ];
    }

    get length() {
        return this.brands.length;
    }

    [Symbol.iterator]() {
        if (this.index === undefined) {
            this.index = 0;
        }
        return {
          next: () => {
            if (this.index < this.brands.length) {
              return {value: this.brands[this.index++], done: false}
            } else {
              this.index = 0  // If you want to iterate over this again without forcing manual update of the index
              return {done: true}
            }
          }
        }
    }

    // The constructor cannot be changed!
    constructor(){
        return this
    }
}

function print() {
    return Array.from(new BrandCollector()).join(',')
}

for (let o of new BrandCollector()) {
    console.log(o);
}
console.log(print())

