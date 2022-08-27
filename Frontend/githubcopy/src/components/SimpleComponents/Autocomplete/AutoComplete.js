import React, { Component, Fragment } from "react";
import PropTypes from "prop-types";
import SVG from "../../SimpleComponents/SVG";
class Autocomplete extends Component {
  static propTypes = {
    suggestions: PropTypes.instanceOf(Array),
  };

  static defaultProps = {
    suggestions: [],
  };

  constructor(props) {
    super(props);

    this.state = {
      // The active selection's index
      activeSuggestion: 0,
      // The suggestions that match the user's input
      filteredSuggestions: [],
      // Whether or not the suggestion list is shown
      showSuggestions: true,
      // What the user has entered
      userInput: "",
    };
  }
  onHover = (index) => {
    const { filteredSuggestions } = this.state;
    this.setState({
      activeSuggestion: index,
      filteredSuggestions,
      showSuggestions: true,
      userInput: this.state.userInput,
    });
  };
  onChange = (e) => {
    const { suggestions } = this.props;
    const userInput = e.currentTarget.value;

    // Filter our suggestions that don't contain the user's input
    const filteredSuggestions = [
      userInput,
      ...suggestions.filter(
        (suggestion) =>
          suggestion.name.toLowerCase().indexOf(userInput.toLowerCase()) > -1
      ),
    ];

    this.setState({
      activeSuggestion: 0,
      filteredSuggestions,
      showSuggestions: true,
      userInput: e.currentTarget.value,
    });
  };
  onLeave = (e) => {
    this.setState({
      activeSuggestion: 0,
      filteredSuggestions: [],
      showSuggestions: false,
      userInput: this.state.userInput,
    });
  };
  onClick = (e) => {
    const { suggestions } = this.props;
    this.setState({
      activeSuggestion: 0,
      filteredSuggestions: suggestions,
      showSuggestions: true,
      userInput: this.state.userInput || e.currentTarget.innerText,
    });
  };

  onKeyDown = (e) => {
    const { activeSuggestion, filteredSuggestions } = this.state;

    // User pressed the enter key
    if (e.keyCode === 13) {
      this.setState({
        activeSuggestion: 1,
        showSuggestions: false,
        userInput: filteredSuggestions[activeSuggestion].name,
      });
    }
    // User pressed the up arrow
    else if (e.keyCode === 38) {
      if (activeSuggestion === 0) {
        return;
      }

      this.setState({ activeSuggestion: activeSuggestion - 1 });
    }
    // User pressed the down arrow
    else if (e.keyCode === 40) {
      if (activeSuggestion + 1 === filteredSuggestions.length) {
        return;
      }

      this.setState({ activeSuggestion: activeSuggestion + 1 });
    }
  };

  render() {
    const {
      onChange,
      onClick,
      onKeyDown,
      onLeave,
      onHover,
      state: {
        activeSuggestion,
        filteredSuggestions,
        showSuggestions,
        userInput,
      },
    } = this;

    let suggestionsListComponent;

    if (showSuggestions) {
      if (filteredSuggestions.length) {
        suggestionsListComponent = (
          <ul className="suggestions">
            {filteredSuggestions.map((suggestion, index) => {
              let className;

              // Flag the active suggestion with a class
              if (index === activeSuggestion) {
                className = "suggestion-active";
              }
              return (
                <li
                  className={className}
                  key={suggestion.name}
                  onMouseOver={() => onHover(index)}
                  onClick={onClick}
                >
                  <SVG
                    key={index}
                    type={suggestion.type}
                    name={index === activeSuggestion && "suggestionSVG"}
                  />
                  {suggestion.name || suggestion}
                </li>
              );
            })}
          </ul>
        );
      }
    }

    return (
      <Fragment>
        <input
          type="text"
          onFocus={onClick}
          onBlur={onLeave}
          onChange={onChange}
          onKeyDown={onKeyDown}
          value={userInput}
          placeholder="Search or jump to…"
          data-unscoped-placeholder="Search or jump to…"
          data-scoped-placeholder="Search or jump to…"
          autocapitalize="off"
          role="combobox"
          aria-haspopup="listbox"
          aria-expanded="false"
          aria-autocomplete="list"
          aria-controls="jump-to-results"
          aria-label="Search or jump to…"
        />
        {suggestionsListComponent}
      </Fragment>
    );
  }
}

export default Autocomplete;
