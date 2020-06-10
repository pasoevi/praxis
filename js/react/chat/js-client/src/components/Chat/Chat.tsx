import React from "react";
import { useSelector } from "react-redux";
import { MessageComponent } from "../Message/Message";
import { AppState } from "../../store";
import { Message } from "../../chat/types";

export interface ChatProps {}

export const Chat: React.FC<ChatProps> = (props) => {
    const messages: Message[] = useSelector(
        (state: AppState) => state.chat.messages,
    );
    return (
        <div className="chat">
            {messages.map((m) => (
                <MessageComponent message={m} key={m.id} />
            ))}
        </div>
    );
};
