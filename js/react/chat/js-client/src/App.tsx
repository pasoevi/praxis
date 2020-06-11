import React from "react";
import "./App.scss"; // Don't look at this
import { Chat } from "./components/Chat/Chat";
import { SendMessage } from "./components/SendMessage/SendMessage";

export default function App() {
    return (
        <div className="App">
            <Chat />
            <SendMessage />
        </div>
    );
}
