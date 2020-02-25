import * as styles from "./SelectedCurrency.module.css";
import React from "react";
import { IsoCurrency } from "./Currency";

export interface SelectedCurrencyProps {
  isoCurrency: IsoCurrency;
  onDeselect: () => void;
}

export const SelectedCurrency: React.FC<SelectedCurrencyProps> = (props) => {
  return (
    <div className={styles["currency"]}>
      <div className={styles.title}>{props.isoCurrency}</div>
      {/* TODO: Configure babel to remove data-roles used by tests */}
      <div className={styles["deselect"]} onClick={props.onDeselect} data-role="deselect">
        X
      </div>
    </div>
  );
};
