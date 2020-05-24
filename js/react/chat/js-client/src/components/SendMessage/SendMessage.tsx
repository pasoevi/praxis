import React, { FunctionComponent, useState, ChangeEvent, FormEvent } from "react";
import { useDispatch } from "react-redux";
import { sendMessage } from "../../state/store/chat/actions";

interface SendMessageProps {
    message?: string;
}

export const SendMessage: FunctionComponent<SendMessageProps> = ({
    message: message = "",
}) => {
    const dispatch = useDispatch();
    const [messageText, setMessageText] = useState(message);

    function handleTextInputChange(e: ChangeEvent<HTMLInputElement>) {
        setMessageText(e.target.value);
    }

    function handleSendMessage(e: FormEvent<HTMLFormElement>) {
        dispatch(sendMessage(messageText));
        e.preventDefault();
    }

    return (
        <form onSubmit={handleSendMessage}>
            <label>
                <input type="text" onChange={handleTextInputChange} />
            </label>
            <button type="submit" value="Send">Send</button>
        </form>
    );
};
