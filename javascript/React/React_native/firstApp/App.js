import { StatusBar } from 'expo-status-bar';
import { StyleSheet, Text,SafeAreaView,Image,TouchableOpacity   } from 'react-native';

export default function App() {
  const handlePress = ()=> console.log("Test")
  return (
    <SafeAreaView style={styles.container}>
      <Text numberOfLines={1} onPress={handlePress}>Buratti is gay</Text>
      <StatusBar style="auto" />
      <TouchableOpacity  onPress={handlePress}>
        <Image onPress={handlePress} style={styles.stretch} source={require("./assets/poggersImage.png")} />
      </TouchableOpacity >
    </SafeAreaView>
  );
}


const styles = StyleSheet.create({
  container: {
    flex: 1,
    backgroundColor: 'white',
    alignItems: 'center',
    justifyContent: 'center',
  },
  stretch: {
    width: 200,
    height: 200,
    resizeMode: 'stretch',
    
  },
});
