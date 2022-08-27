import React from "react";
import "./Header.css";
import json from "../../Images";

const Header = () => {
  return (
    <header>
        <img
          id={json.githubIcon.id}
          src={json.githubIcon.image}
          alt={json.githubIcon.alt}
          className="c"
        />
        <input  spellCheck="false" autoComplete="off" aria-label="Search or jump to…" type="text" placeholder="Search or jump to…" data-unscoped-placeholder="Search or jump to…" data-scoped-placeholder="Search or jump to…" autoCapitalize="off" role="combobox" aria-haspopup="listbox" aria-expanded="false" aria-autocomplete="list" aria-controls="jump-to-results"/>
    </header>
  );
};

export default Header;
