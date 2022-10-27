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
  Dimensions
} from "react-native";
import { useDimensions,useDeviceOrientation } from "@react-native-community/hooks";

export default function App() {
  
  
  return (
    <SafeAreaView style={styles.container}>
      <View style={styles.view}>
        <Image
          style={styles.stretch}
          source={require("./assets/poggersImage.png")}
        />
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
    padding: 10,
    resizeMode: "stretch",
  },
  view:{
    backgroundColor: "red",
    width:"100%",
    height: useDeviceOrientation().landscape ? "100%": "30%",
  }
});
