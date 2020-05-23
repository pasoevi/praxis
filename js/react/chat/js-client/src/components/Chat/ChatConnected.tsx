import React from "react";
import { MessageComponent } from "../Message/Message";
import { connect, MapStateToProps } from "react-redux";
import { AppState } from "../../state/store";
import { sendMessage } from "../../state/state";
import { Message } from "../../state/store/chat/types";
import { Chat } from "./Chat";

export interface ChatConnectedOwnProps {}

export interface ChatConnectedDispatchProps {
    messages: Array<Message>;
}

const mapStateToProps = (state: AppState) => ({
    isLoading: true,
    messages: state.chat.messages,
});

const dispatchProps = {
    sendMessage: () => sendMessage,
};

export const ChatConnected = connect(mapStateToProps, dispatchProps)(Chat);
