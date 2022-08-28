import React from "react";
import "./Header.css";
import json from "../../static/Images/Images";
import Autocomplete from "../SimpleComponents/Autocomplete/AutoComplete";
import "../SimpleComponents/Autocomplete/Autocomplete.css";
import autocompletedata from "../../static/data/AutoComplete";
import ProfileIcon from "../SimpleComponents/ProfileIcon/ProfileIcon";
const Header = () => {
  return (
    <header>
      <img
        id={json.githubIcon.id}
        src={json.githubIcon.image}
        alt={json.githubIcon.alt}
      />
      <div id="headertext">
        <Autocomplete suggestions={autocompletedata} />
        <ul>
          {["Pull requests", "Issues", "Marketplace", "Explore"].map((text) => {
            return (
              <li key={text} className="textHeader">
                <p>{text}</p>
              </li>
            );
          })}
        </ul>
      </div>
      <ProfileIcon image={json.ProfileIconfeijoes.image} />
    </header>
  );
};

export default Header;
