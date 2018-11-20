import * as React from "react";
import { storiesOf } from "@storybook/react";
// import { action } from "@storybook/addon-actions";
import { TaskList } from "./index";

storiesOf('TaskList', module).add(
        'empty',
        () => <TaskList />,
        { info: { inline: true } }
    );