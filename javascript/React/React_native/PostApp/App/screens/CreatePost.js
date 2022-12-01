import { StyleSheet, Text, View } from "react-native";
import React from "react";

export default function CreatePost() {
  return (
    <View style={styles.container}>
      <View style={styles.messageBlue}>
        <Text style={styles.messageContent}>Post1</Text>
        <View>
          <Text>SMG 13:37</Text>
        </View>
      </View>
      <View style={styles.messageOrange}>
        <Text style={styles.messageContent}>Post 2</Text>
        <View >
          <Text>Test</Text>
        </View>
      </View>
    </View>
  );
}

const styles = StyleSheet.create({
container: {
  width: 400,
  padding: 10,
},
messageBlue : {
  position: "relative",
  marginLeft: 20,
  marginBottom: 10,
  padding: 10,
  backgroundColor: "#A8DDFD",
  width: 200,
  height: 50,
  textAlign: "left",
  borderWidth: 1,
  borderColor: "#A7C6E3",
  borderRadius: 10,
},
messageOrange :{
  position: "relative",
  marginBottom: 10,
  marginLeft: "80%",
  padding: 10,
  backgroundColor: "green",
  width: 200,
  height: 50,
  textAlign: "left",
  borderWidth: 1,
  borderColor: "#dfd087",
  borderRadius: 10,
},

messageContent :{
  padding: 0,
  margin: 0,
}
});
