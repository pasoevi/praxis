# Currency Selection

It is possible to specify maximum number currencies that can be selected ( `MaxCurrencies` in `src\currencySelection\currencySelection.tsx`)

## Running in development mode

In the project directory, run:

`yarn install`

`yarn start`

Open [http://localhost:3000](http://localhost:3000) to view it in the browser.

## Run tests

Tests are written using `jest` and `enzyme`.

`yarn test`

## Build for production

 `yarn build`

Builds the minified app for production to `build`.

## Things to improve

* Add stricter rules for eslint
* Configure css loader to not need module in css files.
* Add data-* attributes to select elements from tests (but
  configure babel to remove them when building for production)or
  mock CSS Modules https://jestjs.io/docs/en/webpack#mocking-css-modules
* Setup visual testing using webdriver.io