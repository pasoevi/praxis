import React, { useState } from "react";
import * as styles from "./currencyComponent.module.css";

export enum IsoCurrency {
  EUR = "EUR",
  PLN = "PLN",
  GEL = "GEL",
  DKK = "DKK",
  CZK = "CZK",
  GBP = "GBP",
  SEK = "SEK",
  USD = "USD",
  RUB = "RUB",
}

export interface CurrencyComponentProps {
  selected: boolean;
  isoCurrency: IsoCurrency;
}

export const CurrencyComponent: React.FC<CurrencyComponentProps> = (props) => {
  const [isSelected, setSelected] = useState(props.selected);
    return (
      <div className={styles["currency"]}>
        <div className={styles.title}>{props.isoCurrency}</div>
        {isSelected &&
          <div className={styles["deselect"]} onClick={() => setSelected(false)}>X</div>
        }
      </div>
    );
  }
