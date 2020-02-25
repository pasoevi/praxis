import React from 'react';
import './App.css';
import { IsoCurrency } from './CurrencySelection/Currency';
import { CurrencySelection } from './CurrencySelection/CurrencySelection';

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
