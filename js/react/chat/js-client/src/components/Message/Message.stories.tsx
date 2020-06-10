import React from "react";
import { MessageComponent } from "./Message";
import { WithFigma } from "storybook-addon-figma";

export default {
    title: "Chat message",
    component: MessageComponent,
};

const msgData = {
    text: "Hey",
    id: "87sd87s8df787sd98f7sd9f",
    author: "Sergo Pasoevi",
    timestamp: Date.now(),
};

export const Message = () => (
           <WithFigma
               url={
                   // "https://www.figma.com/file/LbcvMJxDtshDmYtdyfJfkA72/Button-Primary"
                   "https://www.figma.com/file/GSKRTwhXLBqUekKzbW5YmJ/chat-app?node-id=2%3A4/Rectangle 1"
               }
           >
               <MessageComponent message={msgData} />
           </WithFigma>
       );
