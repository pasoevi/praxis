import React from "react";
import { MessageComponent } from "./Message";

export default {
    title: "Chat message",
    component: MessageComponent,
};

const msgData = {
    text: "Hey",
    id: "87sd87s8df787sd98f7sd9f",
    author: "Sergo Pasoevi",
    timestamp: Date.now(),
}

export const Message = () => <MessageComponent message={msgData}/>;
/*
export const Emoji = () => (
    <Button onClick={action("clicked")}>
        <span role="img" aria-label="so cool">
            😀 😎 👍 💯
        </span>
    </Button>
);
 */