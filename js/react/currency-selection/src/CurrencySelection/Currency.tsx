import * as styles from "./Currency.module.css";
import React from "react";
import classNames from "classnames";

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
    <div className={classNames(styles["currency"], {
      [styles["selected"]]: currency.selected,
    })} onClick={() => onChange(currency, !currency.selected)}>
      <input
        name="isSelected"
        type="checkbox"
        onChange={() => { /* handled in onClick of component root div*/}}
        checked={currency.selected}
      />
      <div className={styles.title}>{currency.isoCurrency}</div>
    </div>
  );
};
