import {
  StyleSheet,
  TextInput,
  View,
  Text,
  Keyboard,
  ActivityIndicator,
  TouchableOpacity,
} from "react-native";
import React from "react";
import Ionicons from "react-native-vector-icons/Ionicons";
import axios from "axios";
import AsyncStorage from "@react-native-async-storage/async-storage";

const API_URL =
  Platform.OS === "ios" ? "http://localhost:5000/" : "http://10.0.2.2:5000/";

export default function CreatePost() {
  const [input, setInput] = React.useState("");
  const [isSending, setIsSending] = React.useState(false);
  const [message, setMessage] = React.useState("");
  const [isError, setIsError] = React.useState(false);
  const sendPost = async () => {
    if (!input){
      setIsError(true)
      setMessage("Body cant be empty")
      return
    }
    setIsSending(true);
    Keyboard.dismiss();
    setInput("");
    let userToken;
    try {
      userToken = await AsyncStorage.getItem("Token");
    } catch (e) {
      console.log(e);
    }
    
    axios
      .post(
        `${API_URL}routes/posts/`,
        { body: input.trim() },
        {
          headers: {
            authorization: userToken,
          },
        }
      )
      .then((request) => {
        setIsSending(false);
        if (request.data.success) {
          setIsError(false);
          setMessage("Created");
        }
      })
      .catch((error) => {
        setIsSending(false);
        setIsError(true);
        setMessage(
          error?.response?.data?.msg || "Error in connectin to the server"
        );
      });
  };
  return (
    <View style={styles.container}>
      <View style={styles.inputContainer}>
        <TextInput
          style={styles.input}
          placeholder="Body"
          autoCapitalize="none"
          value={input}
          onChangeText={(e) => setInput(e)}
          multiline={true}
        ></TextInput>
      </View>
      <TouchableOpacity style={styles.confirm} onPress={sendPost}>
        <Ionicons name="checkmark" size={25} color={"black"}></Ionicons>
        <Text style={styles.textConfirm}>Confirm</Text>
      </TouchableOpacity>
      <View style={styles.loading}>
        {isSending && <ActivityIndicator size={"large"}></ActivityIndicator>}
        {message && (
          <Text style={[styles.message, { color: isError ? "red" : "green" }]}>
            {message}
          </Text>
        )}
      </View>
    </View>
  );
}

const styles = StyleSheet.create({
  container: {
    flex: 1,
    alignItems: "center",
    justifyContent: "flex-start",
  },
  inputContainer: {
    backgroundColor: "#A8DDFD",
    width: "70%",
    height: "20%",
    marginTop: 100,
    borderRadius: 30,
    minHeight: 200,
  },
  input: {
    padding: 20,
    width: "90%",
    paddingTop: 10,
    fontSize: 18,
    minHeight: 40,
  },
  confirm: {
    backgroundColor: "#25D366",
    borderRadius: 100,
    padding: "2%",
    position: "absolute",
    alignItems: "center",
    justifyContent: "center",
    bottom: 20,
    flexDirection: "row",
  },
  textConfirm: {
    color: "black",
    fontWeight: "bold",
  },
  loading: {
    marginTop: "20%",
    alignItems: "center",
    justifyContent: "center",

  },
  message: {
    fontSize: 20,
  },
});
