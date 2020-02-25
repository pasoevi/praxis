import * as styles from "./currencyComponent.module.css";
import React, { useState, } from "react";

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

export interface SelectedCurrencyComponentProps {
  isoCurrency: IsoCurrency;
  onDeselect: () => void;
}

export interface CurrencyComponentProps {
  selected: boolean;
  isoCurrency: IsoCurrency;
  onChange: () => void;
}

export const CurrencyComponent: React.FC<CurrencyComponentProps> = (props) => {
  return (
    <div className={styles["currency"]}>
      <input
        name="isSelected"
        type="checkbox"
        checked={props.selected}
        onChange={props.onChange}
      />
      <div className={styles.title}>{props.isoCurrency}</div>
      {props.selected && (
        <div className={styles["deselect"]} onClick={props.onChange}>
          X
        </div>
      )}
    </div>
  );
};

export const SelectedCurrencyComponent: React.FC<SelectedCurrencyComponentProps> = (props) => {
  return (
    <div className={styles["currency"]}>
      <div className={styles.title}>{props.isoCurrency}</div>
      <div className={styles["deselect"]} onClick={props.onDeselect}>
        X
      </div>
    </div>
  );
};
