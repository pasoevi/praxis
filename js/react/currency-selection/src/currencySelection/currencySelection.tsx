import React from 'react'
import {
  CurrencyComponentProps,
  CurrencyComponent,
  IsoCurrency
} from './currencyComponent'
import * as styles from './currencySelection.module.css'

export interface CurrencySelectionState {
  currencies: Array<CurrencyComponentProps>
}

export interface CurrencySelectionProps {
  currencies: Array<IsoCurrency>
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

  render() {
    const currencies = this.state.currencies
    const selectedCurrencies = currencies.filter(c => c.selected)
    return (
      <div className={styles['currency-selection']}>
        <SelectedCurrencies currencies={selectedCurrencies} />
        <AvailableCurrencies currencies={currencies} />
      </div>
    )
  }
}

export class SelectedCurrencies extends React.Component<
  CurrencySelectionState
> {
  render() {
    return <div className={styles['selection']}>
      {this.props.currencies.map((c) => (
        <CurrencyComponent isoCurrency={c.isoCurrency} selected={true} />
      ))}
    </div>
  }
}

export const AvailableCurrencies: React.FC<CurrencySelectionState> = props => {
  const { currencies } = props
  return (
    <div className={styles['available']}>
      {currencies.map(currency => (
        <CurrencyComponent
          selected={currency.selected}
          isoCurrency={currency.isoCurrency}
        />
      ))}
    </div>
  )
}
