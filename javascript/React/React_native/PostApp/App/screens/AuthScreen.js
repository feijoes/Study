import React, { useState } from "react";
import {
  View,
  Text,
  StyleSheet,
  TouchableOpacity,
  TextInput,
  Platform,
} from "react-native";
import axios from "axios";

const API_URL =
  Platform.OS === "ios" ? "http://localhost:5000/" : "http://10.0.2.2:5000/";

export const AuthScreen = () => {
  const [inputs, setInputs] = useState({});
  const [isLogin, setIsLogin] = useState(true);
  const [message, setMessage] = useState("");
  const [isError, setIsError] = useState(false);

  const SendData = async () => {
    if (!(inputs.name && inputs.email && inputs.password)) {
      setIsError(true);
      setMessage("Complete all forms");
      return;
    }
    if (!inputs.confirmPassword === inputs.password) {
      setIsError(true);
      setMessage("Passwords Must Be The Same");
      return;
    } else {
      const body = !isLogin
        ? {
            username: inputs.name,
            email: inputs.email,
            password: inputs.password,
          }
        : {
            username: inputs.name,
            password: inputs.password,
          };

      const request = await axios.post(
        `${API_URL}"routes/users/${isLogin ? "login" : "register"}`,
        body,
        { withCredentials: true }
      );
      const response = await request.json();
      console.log(response);
      setInputs({});
    }
  };

  const onChangeHandler = (value, name) => {
    setInputs((values) => ({ ...values, [name]: value }));
    console.log(inputs);
  };

  const changelogin = () => {
    setIsLogin(!isLogin);
    setMessage("");
  };
  return (
    <View style={styles.card}>
      <Text style={styles.heading}>{isLogin ? "Login" : "Signup"}</Text>
      <View style={styles.form}>
        <View style={styles.inputs}>
          <TextInput
            style={styles.input}
            placeholder="Email"
            autoCapitalize="none"
            name="email"
            value={inputs.email || ""}
            onChangeText={(e) => onChangeHandler(e, "email")}
          ></TextInput>
          {!isLogin && (
            <TextInput
              style={styles.input}
              placeholder="Name"
              name="name"
              value={inputs.name || ""}
              onChangeText={(e) => onChangeHandler(e, "confirmPassword")}
            ></TextInput>
          )}
          <TextInput
            secureTextEntry={true}
            style={styles.input}
            placeholder="Password"
            name="password"
            value={inputs.password || ""}
            onChangeText={(e) => onChangeHandler(e, "password")}
          ></TextInput>
          <TextInput
            secureTextEntry={true}
            style={styles.input}
            placeholder="Confirm Password"
            value={inputs.confirmPassword || ""}
            name="confirmPassword"
            onChangeText={(e) => onChangeHandler(e, "confirmPassword")}
          ></TextInput>
          {message && (
            <Text
              style={[styles.message, { color: isError ? "red" : "green" }]}
            >
              {message}
            </Text>
          )}
          <TouchableOpacity style={styles.button} onPress={SendData}>
            <Text style={styles.buttonText}>Done</Text>
          </TouchableOpacity>
          <TouchableOpacity style={styles.buttonAlt} onPress={changelogin}>
            <Text style={styles.buttonAltText}>
              {isLogin ? "Sign Up" : "Log In"}
            </Text>
          </TouchableOpacity>
        </View>
      </View>
    </View>
  );
};

const styles = StyleSheet.create({
  image: {
    flex: 1,
    width: "100%",
    alignItems: "center",
  },
  card: {
    flex: 1,
    backgroundColor: "rgba(255, 255, 255, 0.4)",
    width: "80%",
    marginTop: "40%",
    borderRadius: 20,
    maxHeight: 380,
    paddingBottom: "30%",
  },
  heading: {
    fontSize: 30,
    fontWeight: "bold",
    marginLeft: "10%",
    marginTop: "5%",
    marginBottom: "30%",
    color: "black",
  },
  form: {
    flex: 1,
    justifyContent: "space-between",
    paddingBottom: "5%",
  },
  inputs: {
    width: "100%",
    flex: 1,
    alignItems: "center",
    justifyContent: "center",
    paddingTop: "10%",
  },
  input: {
    width: "80%",
    borderBottomWidth: 1,
    borderBottomColor: "black",
    paddingTop: 10,
    fontSize: 16,
    minHeight: 40,
  },
  button: {
    width: "80%",
    backgroundColor: "black",
    height: 40,
    borderRadius: 50,
    justifyContent: "center",
    alignItems: "center",
    marginVertical: 3,
  },
  buttonText: {
    color: "white",
    fontSize: 16,
    fontWeight: "400",
  },
  buttonAlt: {
    width: "80%",
    borderWidth: 1,
    height: 40,
    borderRadius: 50,
    borderColor: "black",
    justifyContent: "center",
    alignItems: "center",
    marginVertical: 5,
  },
  buttonAltText: {
    color: "black",
    fontSize: 16,
    fontWeight: "400",
  },
  message: {
    fontSize: 16,
    marginVertical: "5%",
    height: "100%",
    width: "80%",
  },
});
