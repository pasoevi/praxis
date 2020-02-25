/* eslint-disable @typescript-eslint/no-explicit-any */
import React from "react";
import { shallow } from "enzyme";
import { CurrencyComponent } from "./Currency";
import * as styles from "./Currency.module.css";

describe("CurrencyComponent", () => {
  it("renders selected component", () => {
    const onChange = jest.fn();
    const currency = {
      isoCurrency: "PLN" as any,
      selected: true,
    };
    const subject = shallow(<CurrencyComponent currency={currency} onChange={onChange} />);
    expect(subject.hasClass(styles.selected)).toBe(true);
  });

  it("renders not selected component without selected className", () => {
    const onChange = jest.fn();
    const currency = {
      isoCurrency: "PLN" as any,
      selected: false,
    };
    const subject = shallow(<CurrencyComponent currency={currency} onChange={onChange} />);
    expect(subject.hasClass(styles.selected)).not.toBe(true);
  });

  it("renders component with correct currency", () => {
    const onChange = jest.fn();
    const currency = {
      isoCurrency: "PLN" as any,
      selected: false,
    };
    const subject = shallow(<CurrencyComponent currency={currency} onChange={onChange} />);
    // TODO: As mentioned in the README.md, add a better way to select elements form tests
    expect(subject.find("div>div").text()).toEqual("PLN");
  });

  it("calls onChange funtion when clicked", () => {
    const onChange = jest.fn();
    const currency = {
      isoCurrency: "PLN" as any,
      selected: true,
    };
    const subject = shallow(<CurrencyComponent currency={currency} onChange={onChange} />);
    subject.simulate("click");
    expect(onChange).toHaveBeenCalledWith({
      isoCurrency: "PLN" as any,
      selected: true,
    }, false);
  });
});
