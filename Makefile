.PHONY: clean All

All:
	@echo "----------Building project:[ cImgProcessing - Debug ]----------"
	@"$(MAKE)" -f  "cImgProcessing.mk"
clean:
	@echo "----------Cleaning project:[ cImgProcessing - Debug ]----------"
	@"$(MAKE)" -f  "cImgProcessing.mk" clean
