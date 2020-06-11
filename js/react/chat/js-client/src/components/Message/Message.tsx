import React from "react";
import * as styles from "./Message.module.scss";
import { Message } from "../../store/chat/types";

export interface MessageProps extends Message {}

export const MessageComponent: React.FC<MessageProps> = React.memo(
    ({ text, author, id, timestamp }) => {
        return <div className={styles.message}>{text}</div>;
    },
);
