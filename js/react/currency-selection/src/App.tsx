import React from 'react';
import './App.css';
import { IsoCurrency } from './currencySelection/currencyComponent';
import { CurrencySelection } from './currencySelection/currencySelection';

const currencies = [
  IsoCurrency.CZK,
  IsoCurrency.DKK,
  IsoCurrency.EUR,
  IsoCurrency.GBP,
  IsoCurrency.GEL,
  IsoCurrency.PLN,
  IsoCurrency.RUB,
  IsoCurrency.SEK,
  IsoCurrency.USD,
];



function App() {
  return (
    <div className="App">
      <CurrencySelection currencies={currencies} />
    </div>
  );
}

export default App;
