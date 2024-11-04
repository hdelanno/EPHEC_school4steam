<script setup>
    const props = defineProps({
        mean: Number,
        units: String
    })
    const mesuredValue = ref(65);

    onMounted(() => {
            setInterval(updateValue, 200);
        });
    function updateValue() {
        mesuredValue.value = Math.floor(Math.random()*10-5 + (props.mean || 65));
    };
</script>

<template>
    <div>
        {{ mesuredValue }} {{ units || "%" }}
    </div>
</template>

<style scoped>
div {
    border-radius: 10px; 
    background: rgb(238, 238, 238); 
    text-align: center; 
    align-content: center;
}
</style>