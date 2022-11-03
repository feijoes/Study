import { StyleSheet, View, Text, ImageBackground } from "react-native";
const imagebackground = require("../assets/_background.jpg");
export default function Welcome() {
  return (
    <View style={styles.container}>
      <ImageBackground
        source={imagebackground}
        resizeMode="cover"
        style={styles.image}
      ></ImageBackground>
      <Text>React Native</Text>
    </View>
  );
}
const styles = StyleSheet.create({
  container: {
    flex: 1,
    padding: 24,
    backgroundColor: "#eaeaea",
  },
  image: {
    flex: 1,
    justifyContent: "center"
  },
  title: {
    marginTop: 16,
    paddingVertical: 8,
    borderWidth: 4,
    borderColor: "#20232a",
    borderRadius: 6,
    backgroundColor: "#61dafb",
    color: "#20232a",
    textAlign: "center",
    fontSize: 30,
    fontWeight: "bold",
  },
});
