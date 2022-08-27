import React from "react";
import "./Header.css";
import json from "../../static/Images/Images";
import Autocomplete from "../SimpleComponents/Autocomplete/AutoComplete";
import "../SimpleComponents/Autocomplete/Autocomplete.css";
import autocompletedata from "../../static/data/AutoComplete";
const Header = () => {
  return (
    <header>
      <img
        id={json.githubIcon.id}
        src={json.githubIcon.image}
        alt={json.githubIcon.alt}
      />
      <Autocomplete
        suggestions={autocompletedata}
      />
    </header>
  );
};

export default Header;
