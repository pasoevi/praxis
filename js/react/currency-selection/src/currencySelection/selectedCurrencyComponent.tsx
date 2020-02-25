import * as styles from "./selectedCurrencyComponent.module.css";
import React from "react";
import { IsoCurrency } from "./currencyComponent";

export interface SelectedCurrencyComponentProps {
  isoCurrency: IsoCurrency;
  onDeselect: () => void;
}

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
