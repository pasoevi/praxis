import * as React from "react";
import { storiesOf } from "@storybook/react";
import { Task } from "./index"

// import { action } from "@storybook/addon-actions";
import { TaskList } from "./index";

storiesOf('TaskList', module).add(
        'empty',
        () => <Task />,
        { info: { inline: true } }
    );