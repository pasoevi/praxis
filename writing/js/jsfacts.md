# Facts

## Object creation

1. Object literal

    ```JS
    const obj = {}
    // Same as
    Object.create(null)
    ```

2. Object constructor (Not recommended)

    ```JS
    const obj = new Object();
    ```

3. Object.create

    A prototype can be passed to the Object.create  function

    ```JS
    const obj = Object.create();
    ```

4. Function constructor

    ```JS
    function Person(name, address) {
        const obj = {};
        obj.name = name;
        obj.address = address;
        return obj;
    }

    const john = new Person("Josh", "12, Rawl Rue 87923");

    ```
