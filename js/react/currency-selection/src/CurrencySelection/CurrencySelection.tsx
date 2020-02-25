import * as styles from "./CurrencySelection.module.css";
import React from "react";
import {
  Currency,
  CurrencyComponent,
  CurrencyComponentProps,
  IsoCurrency,
} from "./Currency";
import { SelectedCurrency } from "./SelectedCurrency";

const MaxCurrencies = 6;

export interface CurrencySelectionState {
  currencies: Array<Currency>;
}

export interface CurrencySelectionProps {
  currencies: Array<IsoCurrency>;
}

export interface SelectedCurrenciesProps {
  currencies: Array<Currency>;
  onChange: (currency: Currency, selected: boolean) => void;
}

export interface CurrencyProps {
  currencies: Array<CurrencyComponentProps>;
}

export class CurrencySelection extends React.Component<
  CurrencySelectionProps,
  CurrencySelectionState
> {
  constructor(props: CurrencySelectionProps) {
    super(props);

    this.state = {
      currencies: props.currencies.map((c) => ({
        isoCurrency: c,
        selected: false,
      })),
    };
  }

  onCurrencyChanged = (currency: Currency, selected: boolean): void => {
    if (selected && this.state.currencies.filter((c) => c.selected).length >= MaxCurrencies) {
      return;
    }
    const newCurrencies = this.state.currencies.map((c) =>
      c.isoCurrency === currency.isoCurrency ? { ...c, selected: selected } : c
    );
    this.setState({
      currencies: newCurrencies,
    });
  };

  render() {
    const currencies = this.state.currencies;
    const selectedCurrencies = currencies.filter((c) => c.selected);
    return (
      <div className={styles["currencySelection"]}>
        <SelectedCurrencies
          currencies={selectedCurrencies}
          onChange={this.onCurrencyChanged}
        />
        <AvailableCurrencies onChange={this.onCurrencyChanged} currencies={currencies} />
      </div>
    );
  }
}

export class SelectedCurrencies extends React.Component<
  SelectedCurrenciesProps
> {
  render() {
    const { currencies, onChange } = this.props;
    return (
      <div className={styles["selectedCurrencies"]}>
        {currencies.length > 0 ? currencies.slice(0, MaxCurrencies).map((c) => (
          <SelectedCurrency
            key={c.isoCurrency}
            isoCurrency={c.isoCurrency}
            onDeselect={() => onChange(c, false)}
          />
        )): (
          <div className={styles["emptyCurrencies"]}>Select currencies below</div>
        )
      }
      </div>
    );
  }
}

export const AvailableCurrencies: React.FC<SelectedCurrenciesProps> = (props) => {
  const { currencies, onChange } = props;
  return (
    <div className={styles["availableCurrencies"]}>
      {currencies.map((currency) => (
        <CurrencyComponent
          key={currency.isoCurrency}
          currency={currency}
          onChange={onChange}
        />
      ))}
    </div>
  );
};
