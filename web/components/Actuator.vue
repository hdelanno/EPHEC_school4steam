<script setup>
    const props = defineProps({
        name: String
    })
    const state = ref(false);

    function toggle() {
        state.value = !state.value;
    };
</script>

<template>
    <div :class="{ active: state}">
        <p>{{ name }}</p>
        <input type="checkbox" v-model="state">{{ state ? "On" : "Off" }}
    </div>
</template>

<style scoped>
div {
    border-radius: 10px; 
    background: rgb(238, 238, 238); 
    text-align: center; 
    align-content: center;
}

.active {
    background: lightgreen; 
}
</style>