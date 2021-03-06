// Copyright 2015-2018 Mail.Ru Group. All Rights Reserved.
#pragma once

#include "CoreTypes.h"
#include "Delegates/Delegate.h"
#include "PsPushNotificationsExtendedTypes.h"
#include "PsPushNotificationsExtendedManager.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(LogPsPushNotificationsExtended, Log, All);

UCLASS()
class UPsPushNotificationsExtendedManager : public UObject
{
	GENERATED_UCLASS_BODY()

public:
	/** Get instance of the manager */
	UFUNCTION(BlueprintPure, meta=(DisplayName = "Get Ps Push Notifications Extended Manager"))
	static UPsPushNotificationsExtendedManager* GetInstance();

	/** Requests authority for push notifications */
	UFUNCTION(BlueprintCallable)
	virtual void RequestPushNotifications();

	/** Adds notifications cathegory */
	UFUNCTION(BlueprintCallable)
	virtual void AddNotificationCategory(const FString& Name, const TArray<FPsNotificationsAction>& Actions);

	/** Sends local notifications with a specified content in a period of time in seconds
	 @return Notification ID
	 */
	UFUNCTION(BlueprintCallable)
	virtual FString SendLocalNotificationFromNow(float SecondsFromNow, const FPsNotification& Notification);

	/** Sends local notifications with a specified content at specified time
	 @return Notification ID
	 */
	UFUNCTION(BlueprintCallable)
	virtual FString SendLocalNotification(const FDateTime& DateTime, bool bLocalTime, const FPsNotification& Notification);

	/** Cleares all notifications */
	UFUNCTION(BlueprintCallable)
	virtual void ClearAllLocalNotifications();

	/** Removes local notification with specified ID */
	UFUNCTION(BlueprintCallable)
	virtual void ClearLocalNotificationsWithId(const TArray<FString>& NotificationsIds);

	/** Gets last notification action id (use at start of the application to navigate user action) */
	UFUNCTION(BlueprintCallable)
	virtual FString GetLastNotificationActivationCode();

	/** Gets last notification action id (use at start of the application to navigate user action) */
	UFUNCTION(BlueprintCallable)
	virtual FString GetLastNotificationActionId();

protected:
	/** Instance pointer for implementations */
	static UPsPushNotificationsExtendedManager* PushNotificationsExtendedManagerInstance;
};
