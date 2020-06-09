import React from "react";
import "./App.scss";
import { Chat } from "./components/Chat/Chat";
import { SendMessage } from "./components/SendMessage/SendMessage";

function App() {
    return (
        <div className="App">
            <Chat />
            <SendMessage />
        </div>
    );
}

export default App;
