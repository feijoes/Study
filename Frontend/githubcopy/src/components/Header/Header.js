import React from "react";
import "./Header.css";
import json from "../../static/Images/Images";
import Autocomplete from "../SimpleComponents/Autocomplete/AutoComplete";
import "../SimpleComponents/Autocomplete/Autocomplete.css";
 
const Header = () => {
  return (
    <header>
      <img
        id={json.githubIcon.id}
        src={json.githubIcon.image}
        alt={json.githubIcon.alt}
        className="c"
      />
      <Autocomplete
        suggestions={[
          "Alligator",
          "Bask",
          "Crocodilian",
          "Death Roll",
          "Eggs",
          "Jaws",
          "Reptile",
          "Solitary",
          "Tail",
          "Wetlands",
        ]}
      />
    </header>
  );
};

export default Header;
