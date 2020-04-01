import * as React from "react";
import { shallow } from "enzyme";

import { TaskList } from ".";

it("renders the heading", () => {
    const result = shallow(<TaskList />).contains(<h1>You have completed all tasks</h1>);
    expect(result).toBeTruthy();
});