import { StyleSheet, Text, View } from 'react-native'
import React from 'react'

const SeePostScreen = () => {
  return (
    <View style={{ flex: 1, alignItems: 'center', justifyContent: 'center'}}>
            <Text
                onPress={() => alert('This is the POST screen.')}
                style={{ fontSize: 26, fontWeight: 'bold' }}>Home Screen</Text>
        </View>
  )
}

export default SeePostScreen

const styles = StyleSheet.create({})