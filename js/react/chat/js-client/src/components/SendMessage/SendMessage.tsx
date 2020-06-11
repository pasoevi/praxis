import React, {
    useState,
    ChangeEvent,
    FormEvent,
} from "react";
import { useDispatch } from "react-redux";
import { sendMessage } from "../../store/chat/actions";

interface SendMessageProps {
    message?: string;
}

const defaultProps: SendMessageProps = {
    message: "",
};

export const SendMessage: React.FC<SendMessageProps> = (props) => {
    const dispatch = useDispatch();
    const { message } = props;
    const [messageText, setMessageText] = useState(message ?? "");

    function handleTextInputChange(e: ChangeEvent<HTMLInputElement>) {
        setMessageText(e.target.value);
    }

    function handleSendMessage(e: FormEvent<HTMLFormElement>) {
        dispatch(sendMessage(messageText));
        setMessageText("");
        e.preventDefault();
    }

    return (
        <form onSubmit={handleSendMessage}>
            <label>
                <input type="text" value={messageText} onChange={handleTextInputChange} />
            </label>
            <button type="submit" value="Send">
                Send
            </button>
        </form>
    );
};

SendMessage.defaultProps = defaultProps;
