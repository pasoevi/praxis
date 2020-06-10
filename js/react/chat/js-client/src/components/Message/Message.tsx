import React from "react";
import * as styles from "./Message.module.scss";
import { Message } from "../../store/chat/types";

export interface MessageProps {
    message: Message;
}

export const MessageComponent: React.FC<MessageProps> = React.memo(
    ({ message }) => {
        return <div className={styles["message"]}>{message.text}</div>;
    },
);
