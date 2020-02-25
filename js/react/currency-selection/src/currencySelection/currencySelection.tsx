import React from 'react'
import {
  CurrencyComponentProps,
  CurrencyComponent,
  IsoCurrency,
  SelectedCurrencyComponent,
  Currency
} from './currencyComponent'
import * as styles from './currencySelection.module.css'

export interface CurrencySelectionState {
  currencies: Array<Currency>
}

export interface CurrencySelectionProps {
  currencies: Array<IsoCurrency>
}

export interface SelectedCurrenciesProps {
  currencies: Array<Currency>;
  onChange: (currency: Currency, selected: boolean) => void;
}

export interface CurrencyProps {
  currencies: Array<CurrencyComponentProps>
}

export class CurrencySelection extends React.Component<
  CurrencySelectionProps,
  CurrencySelectionState
> {
  constructor(props: CurrencySelectionProps) {
    super(props)

    this.state = {
      currencies: props.currencies.map(c => ({
        isoCurrency: c,
        selected: false
      }))
    }
  }

  onCurrencyChanged = (currency: Currency, selected: boolean) => {
    const newCurrencies = this.state.currencies.map(c => c.isoCurrency === currency.isoCurrency ? {...c, selected: selected}: c);
    this.setState({
      currencies: newCurrencies,
    });
  }

  render() {
    const currencies = this.state.currencies;
    const selectedCurrencies = currencies.filter(c => c.selected);
    return (
      <div className={styles["currencySelection"]}>
        <SelectedCurrencies currencies={selectedCurrencies} onChange={this.onCurrencyChanged}/>
        <AvailableCurrencies currencies={currencies} />
      </div>
    )
  }
}

export class SelectedCurrencies extends React.Component<
  SelectedCurrenciesProps
> {
  render() {
    return <div className={styles['selectedCurrencies']}>
      {this.props.currencies.map((c) => (
        <SelectedCurrencyComponent
          isoCurrency={c.isoCurrency}
          onDeselect={() => this.props.onChange(c, false)}
        />
      ))}
    </div>
  }
}

export const AvailableCurrencies: React.FC<CurrencySelectionState> = props => {
  const { currencies } = props
  return (
    <div className={styles['availableCurrencies']}>
      {currencies.map(currency => (
        <CurrencyComponent
          key={currency.isoCurrency}
          selected={currency.selected}
          isoCurrency={currency.isoCurrency}
          onChange={() => console.log()}
        />
      ))}
    </div>
  )
}
