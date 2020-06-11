import React from "react";
import * as styles from "./Message.module.scss";
import { Message } from "../../store/chat/types";

export interface MessageProps extends Message {

}

export const MessageComponent: React.FC<MessageProps> = React.memo(
    (props) => {
        return <div className={styles["message"]}>{props.text}</div>;
    },
);
