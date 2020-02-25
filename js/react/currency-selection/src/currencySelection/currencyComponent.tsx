import * as styles from "./currencyComponent.module.css";
import React from "react";

export enum IsoCurrency {
  EUR = "EUR",
  PLN = "PLN",
  GEL = "GEL",
  DKK = "DKK",
  CZK = "CZK",
  GBP = "GBP",
  SEK = "SEK",
  USD = "USD",
  RUB = "RUB"
}

export interface Currency {
  selected: boolean;
  isoCurrency: IsoCurrency;
}

export interface CurrencyComponentProps {
  currency: Currency;
  onChange: (currency: Currency, selected: boolean) => void;
}

export const CurrencyComponent: React.FC<CurrencyComponentProps> = (props) => {
  const { currency, onChange } = props;
  return (
    <div className={styles["currency"]} onClick={() => onChange(currency, !currency.selected)}>
      <input
        name="isSelected"
        type="checkbox"
        checked={currency.selected}
        onChange={(e: React.ChangeEvent<HTMLInputElement>) => onChange(currency, e.target.checked)}
      />
      <div className={styles.title}>{currency.isoCurrency}</div>
    </div>
  );
};
