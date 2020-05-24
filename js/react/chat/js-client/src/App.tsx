import React from "react";
import "./App.scss";
import { ChatConnected } from "./components/Chat/ChatConnected";
import { SendMessage } from "./components/SendMessage/SendMessage";

function App() {
    return (
        <div className="App">
            <ChatConnected />
            <SendMessage />
        </div>
    );
}

export default App;
