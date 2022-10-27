import {
  StyleSheet,
  Text,
  SafeAreaView,
  Image,
  TouchableNativeFeedback,
  Button,
  Alert,
  Platform,
  StatusBar,
  View,
} from "react-native";

export default function App() {
  console.log();
  const handlePress = (e) => console.log("you are sooo pogers");
  return (
    <SafeAreaView style={styles.container}>
      <Image
        style={styles.stretch}
        source={require("./assets/poggersImage.png")}
      />
      <View style={styles.view}>

      </View>
    </SafeAreaView>
  );
}

const styles = StyleSheet.create({
  container: {
    flex: 1,
    backgroundColor: "white",
    paddingTop: Platform.OS === "android" ? StatusBar.currentHeight : 0,
  },
  stretch: {
    width: 200,
    height: 200,
    padding: 100,
    resizeMode: "stretch",
  },
  view:{
    backgroundColor: "red",
    width:150,
  }
});
